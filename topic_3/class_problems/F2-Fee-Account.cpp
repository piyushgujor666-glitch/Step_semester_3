#include<bits/stdc++.h>
using namespace std;

class FeeAccount {
private:
    string reg_No;
    double totalFee;
    double amountpaid;

public:
    FeeAccount(string reg_No, double totalFee, double amountpaid) {
        this->reg_No = reg_No;
        this->totalFee = totalFee;
        this->amountpaid = amountpaid;
    }

    void pay(double amount) {
        if (amount > 0) {
            amountpaid += amount;
            cout << "Amount paid successfully!" << endl;
        }
        else {
            cout << "Invalid amount!" << endl;
        }
    }

    double getDue() {
        return totalFee - amountpaid;
    }

    void payInTwoInstallments(double amount) {
        double half = amount / 2;
        pay(half);
        pay(half);
    }

    double effectiveDue(double scholarshipPercent) {
        double due = getDue();
        return due - (due * scholarshipPercent / 100);
    }
};

int main() {
    FeeAccount account("REG123", 1000, 200);

    cout << "Due amount: " << account.getDue() << endl;

    account.pay(300);
    cout << "Due amount: " << account.getDue() << endl;

    account.payInTwoInstallments(400);
    cout << "Due amount: " << account.getDue() << endl;

    double effective_due = account.effectiveDue(20);

    cout << "Effective due after scholarship: "
         << effective_due << endl;

    return 0;
}
