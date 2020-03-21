#ifndef TICKETMACHINE_H_
#define TICKETMACHINE_H_

class TicketMachine {
private:
    // 成员变量
    const int PRICE;
    int balance;
    int total;

public:
    // 构造函数与析构函数
    TicketMachine();
    virtual ~TicketMachine();

    //类的方法
    void showPrompt();
    void insertMoney(int money);
    void showBalance();
    void printTicker();
    void showTotal();
};
























#endif /* TICKETMACHINE_H_ */