#include "TicketMachine.h"
#include <iostream>
using namespace std;

void TicketMachine::showPrompt() {
    cout << "something" << endl;
}

void TicketMachine::insertMoney(int money) {
    balance += money;
}

void TicketMachine::showBalance() {
    cout << balance << endl;
}



