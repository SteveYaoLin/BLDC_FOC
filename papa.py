import requests

# 定义要爬取的网页链接
url = 'https://mp.weixin.qq.com/s/CbWrYY_Cig55AK1HFPVE1Q'

# 发起HTTP GET请求获取网页内容
response = requests.get(url)
html = response.text

# 将网页内容写入output.txt文件
with open('output.txt', 'w', encoding='utf-8') as f:
    f.write(html)

print('网页内容已保存到output.txt文件')