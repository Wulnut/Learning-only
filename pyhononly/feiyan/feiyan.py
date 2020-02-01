import json
import requests

history = []

r = requests.post('https://view.inews.qq.com/g2/getOnsInfo',{'name':'wuwei_ww_cn_day_counts'})

history = json.loads(json.loads(r.text)['data'])

with open('D:\\Users\\code\\Learning only\\pyhononly\\feiyan\\history.csv','w',encoding='GBK') as f:
    f.write('date,confirm,dead,suspect,heal\n')
    for item in history:
        f.write(str(item['date']) + ',')
        f.write(str(item['confirm']) + ',')
        f.write(str(item['dead']) + ',')
        f.write(str(item['suspect']) + ',')
        f.write(str(item['heal']) + '\n')
