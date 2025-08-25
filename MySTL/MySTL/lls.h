#pragma once
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> persons(n);
    for (int i = 0; i < n; i++) {
        cin >> persons[i];
    }

    vector<int> prizes(n);
    for (int i = 0; i < n; i++) {
        cin >> prizes[i];
    }

    // 构建每种礼品类型的员工索引队列
    vector<queue<int>> type_queues(n + 1);
    for (int i = 0; i < n; i++) {
        type_queues[persons[i]].push(i);
    }

    // current：当前循环队列的头索引
    // ans：礼品被领取结果（礼品位置 -> 员工ID）
    vector<int> ans(n);
    int current = 0, to_assign = n;

    for (int gift_index = 0; gift_index < n; gift_index++) {
        int prize = prizes[gift_index];
        queue<int>& q = type_queues[prize];

        // 循环直到找到能匹配的员工
        while (true) {
            if (q.empty()) {
                // 从队尾的残余员工中寻找（保证有解）
                while (type_queues[prize].empty()) {
                    prize = (prize + 1) % (n + 1);
                }
                q = type_queues[prize];
            }

            int employee_index = q.front();
            q.pop();

            // 计算相对距离（考虑循环队列）
            int steps;
            if (employee_index >= current) {
                steps = employee_index - current;
            }
            else {
                steps = employee_index - current + to_assign;
            }

            // 如果该员工在剩余的等待员工内
            if (steps < to_assign) {
                to_assign--;
                current = (employee_index + 1) % to_assign;
                ans[gift_index] = employee_index + 1;
                break;
            }
        }
    }

    // 输出结果
    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;

    return 0;
}