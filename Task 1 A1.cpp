// Problem 1: Shopkeeper Simulation with STL

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

struct Product {
    int id;
    int quantity;
    int cost_price;
    int sale_price;
};

struct Query {
    int product_id;
    int quantity;
    int payoff;
};

struct Customer {
    int id;
    int budget;
    vector<Query> queries;
};

struct Transaction {
    string type;
    int customer_id;
    int product_id;
    int quantity;
    int amount;
};

unordered_map<int, Product> products;
vector<Transaction> logs;
int funds = 10000;
int loans = 0;

int knapsack(Customer& customer, vector<Query>& selected_queries) {
    int m = customer.queries.size();
    vector<vector<int>> dp(m+1, vector<int>(customer.budget+1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int b = 0; b <= customer.budget; ++b) {
            dp[i][b] = dp[i-1][b];
            Query q = customer.queries[i-1];
            Product& p = products[q.product_id];
            int total_cost = q.quantity * p.sale_price;
            if (b >= total_cost) {
                dp[i][b] = max(dp[i][b], dp[i-1][b - total_cost] + q.payoff);
            }
        }
    }

    int b = customer.budget;
    for (int i = m; i > 0; --i) {
        Query q = customer.queries[i-1];
        Product& p = products[q.product_id];
        int total_cost = q.quantity * p.sale_price;
        if (b >= total_cost && dp[i][b] != dp[i-1][b]) {
            selected_queries.push_back(q);
            b -= total_cost;
        }
    }

    return dp[m][customer.budget];
}

void process_customer(Customer& c) {
    vector<Query> chosen;
    knapsack(c, chosen);
    for (auto& q : chosen) {
        Product& p = products[q.product_id];
        if (p.quantity < q.quantity) {
            int needed = q.quantity - p.quantity;
            int restock_cost = needed * p.cost_price;
            if (funds >= restock_cost) {
                funds -= restock_cost;
            } else {
                int loan = restock_cost - funds;
                funds = 0;
                loans += loan * 1.1;
            }
            p.quantity += needed;
            logs.push_back({"restock", c.id, p.id, needed, restock_cost});
        }
        int revenue = q.quantity * p.sale_price;
        p.quantity -= q.quantity;
        funds += revenue;
        logs.push_back({"sale", c.id, p.id, q.quantity, revenue});
    }
}

void print_summary() {
    cout << "\n--- Transaction Log ---\n";
    for (auto& t : logs) {
        cout << t.type << ": customer " << t.customer_id << ", product " << t.product_id
             << ", quantity " << t.quantity << ", amount " << t.amount << "\n";
    }
    cout << "Total funds at end: " << funds << endl;
    cout << "Total loan to repay: " << loans << endl;
    cout << "Profit/Loss: " << (funds - loans - 10000) << endl;
