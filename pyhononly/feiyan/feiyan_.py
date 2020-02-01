import json
import requests
from datetime import datetime
from apscheduler.schedulers.blocking import BlockingScheduler

def getinfo():
    r = requests.post('https://view.inews.qq.com/g2/getOnsInfo',{'name':'wuwei_ww_global_vars'})
    data = json.loads(json.loads(r.text)['data'])
    with open('D:\\Users\\code\\Learning only\\pyhononly\\feiyan\\feiyan_log.csv','a',encoding='GBK') as f:
        string = datetime.now().strftime('%Y-%m-%d %H:%M:%S') + ','+ str(data[0]['recentTime']) + ',' + str(data[0]['confirmCount']) + ',' + str(data[0]['suspectCount']) + ',' + str(data[0]['deadCount']) + ',' + str(data[0]['cure']) + '\n'
        f.write(string)
    print(datetime.now().strftime('%Y-%m-%d %H:%M:%S') + ' ' 
            + str(data[0]['recentTime']) + ' ' + str(data[0]['confirmCount']))
    with open('D:\\Users\\code\\Learning only\\pyhononly\\feiyan\\feiyan_y.log','a',encoding='GBK') as f:
        f.write('\'' + str(data[0]['confirmCount']) + '\',')
    with open('D:\\Users\\code\\Learning only\\pyhononly\\feiyan\\feiyan_x.log','a',encoding='GBK') as f:
        f.write('\'' + str(int(datetime.now().strftime('%d'))-13) + '+' + datetime.now().strftime('%H'))
        if datetime.now().strftime('%M') == '30':
            f.write('.5')
        f.write('/24\',')

if __name__ == "__main__":
    scheduler = BlockingScheduler()
    scheduler.add_job(getinfo, 'cron', minute='*/30',end_date='2020-01-30')
    scheduler.start()
#getinfo()
