const axios = require('axios');
const fs = require('fs');

// 定义要爬取的网页链接
const url = 'https://mp.weixin.qq.com/s/CbWrYY_Cig55AK1HFPVE1Q';

// 发起HTTP GET请求获取网页内容
axios.get(url)
  .then(response => {
    const html = response.data;

    // 将网页内容写入output.txt文件
    fs.writeFile('output.txt', html, err => {
      if (err) {
        console.error('写入文件出错：', err);
      } else {
        console.log('网页内容已保存到output.txt文件');
      }
    });
  })
  .catch(error => {
    console.error('请求网页出错：', error);
  });