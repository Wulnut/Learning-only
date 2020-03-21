#include "TicketMachine.h"
#include <iostream>
using namespace std;


int main() {
    TicketMachine tm;

    tm.insertMoney(100);
    tm.showBalance();

    return 0;
}