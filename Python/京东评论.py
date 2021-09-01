import json
import os
import random
import time
import jieba
import requests
import numpy as np
from PIL import Image
import matplotlib.pyplot as plt
from wordcloud import WordCloud

COMMENT_FILE_PATH = 'jd_comment.txt' #评价数据保存文件
WC_FONT_PATH = r'C:\\Windows\\Fonts\\SimHei.ttf' #词云字体

def spider_comment(page = 0):
    #爬取京东评论
    #用户输入商品链接（目前仅支持京东），提取商品代码，插入到url中，例如华为P40的商品代码为100012015188
    itemnum='100012015188' #商品代码itemnum
    url = 'https://club.jd.com/comment/productPageComments.action?callback=fetchJSON_comment98&productId=%s&score=0&sortType=5&page=%s&pageSize=10&isShadowSku=0&fold=1' %(itemnum,page)
    header = {
        'Referer': 'https://item.jd.com/%s.html' %itemnum,
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/80.0.3970.5 Safari/537.36'
    }
    try:
        r = requests.get(url, headers=header)
        r.raise_for_status()
        #print('京东评论数：', r.text[:500])
    except:
        print('爬取失败')
    #截取json数据字符串
    r_json_str = r.text[20:-2]
    #print('京东评论数：' + r_json_str[:500])
    #字符串转json对象
    r_json_obj = json.loads(r_json_str)
    #获取评价列表数据
    r_json_comments = r_json_obj['comments']
    #print('京东评价数据：')
    #遍历评论列表数据
    for r_json_comment in r_json_comments:
        #以追加模式换行写入每条评价
        with open(COMMENT_FILE_PATH, 'a+') as file:
            file.write(r_json_comment['content'] + '\n')
        #获取评论对象中的评论内容
        print(r_json_comment['content'])

def barch_spider_comment():
    #批量爬取京东评价
    #写入数据前先清空之前的数据
    if os.path.exists(COMMENT_FILE_PATH):
        os.remove(COMMENT_FILE_PATH)
    for i in range(10):#限定爬取10页，以控制爬取时间
        spider_comment(i)
        #模拟用户测试，设置一个爬虫间隔，防止IP被封
        time.sleep(random.random() * 5)

def cut_word():
    #对数据分词，return分词后的数据
    with open(COMMENT_FILE_PATH,'r') as file:
        comment_txt = file.read()
        wordlist = jieba.cut(comment_txt, cut_all=True)
        wl = ' '.join(wordlist)
        print(wl)
        return wl

def create_word_cloud():
    #生成词云
    #设置词云的一些配置，如;字体，背景色，词云形状，大小
    wc = WordCloud(background_color='white',max_words=20,scale=4,max_font_size=50, random_state=42, font_path=WC_FONT_PATH)
    #random_state：不同的值会让字图的分布不一样
    #根据文本生成词云
    wc.generate(cut_word())
    wc.to_file("词云.jpg")  #保存词云图片
    plt.imshow(wc, interpolation='bilinear')
    plt.axis('off')
    #plt.figure()
    plt.show()


if __name__ == '__main__':
    barch_spider_comment()
    cut_word()
    create_word_cloud()