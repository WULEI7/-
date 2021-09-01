from tkinter import ttk
from tkinter import *
from tkinter.ttk import *
import tkinter.filedialog
import numpy as np
import jieba
import os
import re
import PIL
import json
import random
import time
import requests
import wordcloud
import matplotlib.pyplot as plt
from collections import Counter
from pylab import mpl
from PIL import Image
from wordcloud import WordCloud


#以下为爬虫部分------------------------------
COMMENT_FILE_PATH = '京东评论文本.txt' #评论数据保存文件
def spider_comment(page = 0): #爬取京东评论
    #用户输入商品链接（目前仅支持京东），提取商品代码，插入到url中，例如华为P40的商品代码为100012015188
    #itemnum='100012015188' #商品代码itemnum
    string = E1.get()
    if re.match(r"https://item.jd.com/\d+.html", string) is None:
        exit()
    s = re.findall(r"\d+", string) #正则表达式匹配输入的商品代码
    itemnum = s[0]
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
        #print('爬取失败')
        #E1.delete(0, END)
        #E1.insert(0, "请输入正确的链接！")
        exit()

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
def barch_spider_comment(): #批量爬取京东评论
    #写入数据前先清空之前的数据
    if os.path.exists(COMMENT_FILE_PATH):
        os.remove(COMMENT_FILE_PATH)
    for i in range(10):#限定爬取10页，以控制爬取时间
        spider_comment(i)
        #模拟用户测试，设置一个爬虫间隔，防止IP被封
        time.sleep(random.random() * 5)
#以上为爬虫部分------------------------------


def stopwordslist():
    stopwords = [line.strip() for line in open('Stopword.txt', encoding='UTF-8').readlines()]
    return stopwords

def get_plt():
    file = E2.get()
    words_str = ""
    with open(file) as f:
        for line in f:
            line = re.sub(u"[0-9\s+.!/,$%^*()?;；:-【】\"\']+|[+—！，;:。？、~@#￥%…&*（）＞＜-]+", "", line)  # 去掉多余字符
            if line == "": continue
            line = line.replace("\n", "")  # 去掉换行符
            seg_list = jieba.cut(line, cut_all=False)
            words_str += (" ".join(seg_list))
    stopwords = stopwordslist()
    words = [word for word in words_str.split(" ") if word not in stopwords and len(word) > 1]
    word_counts = Counter()  # 词频统计
    for x in words:
        word_counts[x] += 1

    x = [i[0] for i in word_counts.most_common(30)]
    y = [i[1] for i in word_counts.most_common(30)]
    fig, ax = plt.subplots()
    ax.barh(range(len(x)), y) #, color='gold'
    ax.set_yticks(range(len(x)))
    ax.set_yticklabels(x)
    plt.rcParams['font.sans-serif'] = [u'SimHei']
    plt.rcParams['axes.unicode_minus'] = False
    plt.title("词频统计图", fontsize=10)
    #plt.ylabel("词")
    plt.xlabel("出现次数")
    plt.savefig('词频统计图.jpg')
    #plt.show()

def get_wordcloud():  # 词云生成
    file = E2.get()
    words_str = ""
    with open(file) as f:
        for line in f:
            line = re.sub(u"[0-9\s+.!/,$%^*()?;；:-【】\"\']+|[+—！，;:。？、~@#￥%…&*（）＞＜-]+", "", line)  # 去掉多余字符
            if line == "": continue
            line = line.replace("\n", "")  # 去掉换行符
            seg_list = jieba.cut(line, cut_all=False)
            words_str += (" ".join(seg_list))
    stopwords = stopwordslist()
    words = [word for word in words_str.split(" ") if word not in stopwords and len(word) > 1]
    word_counts = Counter()  # 词频统计
    for x in words:
        word_counts[x] += 1

    mask = np.array(PIL.Image.open(r'./background.jpg'))
    wc = WordCloud(font_path=r'C:\Windows\Fonts\SimHei.TTF', max_words=2000, mask=mask, repeat=False)
    wc.generate_from_frequencies(word_counts)
    image_colors = wordcloud.ImageColorGenerator(mask)  #基于彩色图像生成相应彩色,文字颜色跟随背景图颜色
    wc.recolor(color_func=image_colors)
    wc.to_file("词云.jpg")
    #plt.imshow(wc)
    #plt.axis('off')
    #plt.show()

def select(): # 实现浏览按钮的功能
    filename = tkinter.filedialog.askopenfilename()
    if filename != "":
        E2.delete(0,END)
        E2.insert(0,filename)



#以下为GUI界面实现------------------------------
win = Tk() # 创建主窗口
win.title('智反馈文本分析 · 简洁便利 精准实用') #窗口上方文字
win.iconbitmap('zfklogo.ico') #窗口左上角图标
sw = win.winfo_screenwidth() #得到屏幕宽度
sh = win.winfo_screenheight() #得到屏幕高度
ww = 600
wh = 400
x = int((sw-ww) / 2) #让界面显示在屏幕中央
y = int((sh-wh) / 2)
win.geometry("{}x{}+{}+{}".format(ww,wh,x,y))

L0 = Label(win,text="欢迎使用智反馈！ 希望给您带来愉快的体验！")
L0.place(x=10,y=10)
L1 = Label(win,text="输入商品链接:")
L1.place(x=10,y=40)
L2 = Label(win,text="选择文本文件:")
L2.place(x=10,y=80)
LL1 = Label(win,text="程序使用说明如下：\n您可以输入商品链接进行爬取评论（目前暂时仅支持京东）\n请耐心等待约30秒，将生成本地文件“京东评论文本.txt”\n您可以点击“浏览”按钮，选择任意本地txt文本文件进行智能文本分析\n点击下方各功能按钮，即可到当前目录下查看生成的数据分析")
LL1.place(x=10,y=200)
LL2 = Label(win,text="更多功能正在开发中，敬请期待！")
LL2.place(x=10,y=150)

E1 = Entry(win,textvariable=StringVar()) #需爬取商品链接
E1.place(x=100,y=40)
E2 = Entry(win,textvariable=StringVar()) #需分析文本路径
E2.place(x=100,y=80)

B0 = Button(win,text="爬取评论",width=10,command=barch_spider_comment)
B0.place(x=260,y=38)

B1 = Button(win,text="浏览",width=10,command=select)
B1.place(x=260,y=78)

B2 = Button(win,text="生成词频统计",command=get_plt)
B2.place(x=10,y=120)

B3 = Button(win,text="生成词云图",command=get_wordcloud)
B3.place(x=100,y=120)

B4 = Button(win,text="情感倾向分析")
B4.place(x=190,y=120)

B5 = Button(win,text="文本聚类")
B5.place(x=280,y=120)

win.mainloop()# 进入消息循环

input("please input any key to exit!")
