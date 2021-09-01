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
def barch_spider_comment(): #批量爬取京东评论
    #写入数据前先清空之前的数据
    if os.path.exists(COMMENT_FILE_PATH):
        os.remove(COMMENT_FILE_PATH)
    for i in range(10):#限定爬取10页，以控制爬取时间
        spider_comment(i)
        #模拟用户测试，设置一个爬虫间隔，防止IP被封
        time.sleep(random.random() * 5)
#以上为爬虫部分------------------------------


def stopwordslist(): #停用词文本
    stopwords = [line.strip() for line in open('Stopword.txt', encoding='UTF-8').readlines()]
    return stopwords


def get_wordtxt():  #分析文本的函数
    file = e1.get()
    txt = open(file, "r").read() #读的方式打开文本文件
    words  = jieba.lcut(txt)  #jieba分词
    counts = {}
    for word in words:
        if len(word) == 1:  #剔除一个字的分词结果
            continue
        else:
            counts[word] = counts.get(word,0) + 1  #按单词统计
    items = list(counts.items())  #转变成列表
    items.sort(key=lambda x:x[1], reverse=True)  #按词频数降序排列
    fo = open("词频结果文本.txt","w+") #覆盖读写模式打开文件.txt
    for i in range(len(items)):  #输出所有高频词
        word, count = items[i]  
        fo.writelines("{0:<10}{1:>5}\n".format(word, count)) #将结果写入.txt文件里
    fo.close()

words_str = ""
with open("result.txt") as f:
    for line in f:
        line = re.sub(u"[a-zA-Z0-9\s+.!/,$%^*()?;；:-【】\"\']+|[+—！，;:。？、~@#￥%…&*（）＞＜-]+", "", line)  # 去掉多余字符
        if line == "": continue
        line = line.replace("\n", "")  # 去掉换行符
        seg_list = jieba.cut(line, cut_all=False)
        words_str += (" ".join(seg_list))

stopwords = stopwordslist()
words = [word for word in words_str.split(" ") if word not in stopwords and len(word) > 1]

word_counts = Counter()  #词频统计
for x in words:
    word_counts[x] += 1
get_plt(word_counts.most_common(30), "词频统计top30")
hotword_top30 = word_counts.most_common(30)
hotword_top30 = {x[0]: x[1] for x in hotword_top30}
get_plt(hotword_top30, "词频统计图top30")


def get_wordcloud(): #得到词云的函数
    file = e1.get()
    txt = open(file,"r").read() #读的方式打开文本文件

    words = jieba.lcut(txt) #jieba分词
    wordc = ' '.join(words) #将分开的词用空格连接，便于生成词云
    stopwords = stopwordslist()
    words = [word for word in words_str.split(" ") if word not in stopwords and len(word) > 1]
    mask = np.array(PIL.Image.open(r'./background.jpg'))
    font = r'C:\Windows\Fonts\SimHei.TTF'  # 设置字体为微软雅黑
    wc = WordCloud(font_path=font, background_color='white', max_words=2000, mask=mask, repeat=False, mode='RGBA').generate(wordc)
    wc.to_file("词云.jpg") #保存词云图片


def get_plt(data, title): #词频统计图绘制
    x = [i[0] for i in data]
    y = [i[1] for i in data]
    fig, ax = plt.subplots()
    ax.barh(range(len(x)), y, color='gold')
    ax.set_yticks(range(len(x)))
    ax.set_yticklabels(x)
    plt.rcParams['font.sans-serif'] = [u'SimHei']
    plt.rcParams['axes.unicode_minus'] = False
    plt.title(title, fontsize=10)
    plt.ylabel("关键词")
    plt.xlabel("出现次数")

    #plt.show()

def plt_tofile():
    words_str = ""
    with open("result.txt") as f:
        for line in f:
            line = re.sub(u"[a-zA-Z0-9\s+.!/,$%^*()?;；:-【】\"\']+|[+—！，;:。？、~@#￥%…&*（）＞＜-]+", "", line)  # 去掉多余字符
            if line == "": continue
            line = line.replace("\n", "")  # 去掉换行符
            seg_list = jieba.cut(line, cut_all=False)
            words_str += (" ".join(seg_list))
    stopwords = stopwordslist()
    words = [word for word in words_str.split(" ") if word not in stopwords and len(word) > 1]

    word_counts = Counter()  # 词频统计
    for x in words:
        word_counts[x] += 1
    get_plt(word_counts.most_common(30), "词频统计top30")
    hotword_top30 = word_counts.most_common(30)
    hotword_top30 = {x[0]: x[1] for x in hotword_top30}
    get_plt(hotword_top30, "词频统计图top30")



#以下为GUI界面实现------------------------------
win = Tk() # 创建主窗口
win.title('智反馈文本分析') #窗口上方文字
win.iconbitmap('zfklogo.ico') #窗口左上角图标
sw = win.winfo_screenwidth() #得到屏幕宽度
sh = win.winfo_screenheight() #得到屏幕高度
ww = 400
wh = 450
x = int((sw-ww) / 2) #让界面显示在屏幕中央
y = int((sh-wh) / 2)
win.geometry("{}x{}+{}+{}".format(ww,wh,x,y))

#Label0 = Label(win,text="加水印").grid(row=0,column=1,padx=10,pady=10)
#Label1 = Label(win,text="选择原图片:").grid(row=1,column=0,padx=10,pady=5)
#Label2 = Label(win,text="输入可视水印:").grid(row=2,column=0,padx=10,pady=5)
#Label3 = Label(win,text="输入数字水印:").grid(row=3,column=0,padx=10,pady=5)
#Label4 = Label(win,text="获取密文").grid(row=4,column=1,padx=10,pady=10)
#Label5 = Label(win,text="选择加密图片:").grid(row=5,column=0,padx=10,pady=5)
Label0 = Label(win,text="欢迎使用智反馈！简洁便利 精准实用").grid(row=0,column=1,padx=10,pady=10)
Label1 = Label(win,text="选择文本:").grid(row=1,column=0,padx=10,pady=5)

#e1 = Entry(win,textvariable=StringVar())# 字符串接收框 用来放原图路径
#e2 = Entry(win,textvariable=StringVar()) #  可视水印内容
#e3 = Entry(win,textvariable=StringVar())#  数字水印内容
#e4 = Entry(win,textvariable=StringVar()) #  需解密图片路径
e1 = Entry(win,textvariable=StringVar()) #  需分析文本路径
#e1.grid(row=1,column=1,padx=10,pady=5)
#e2.grid(row=2,column=1,padx=10,pady=5)
#e3.grid(row=3,column=1,padx=10,pady=5)
#e4.grid(row=5,column=1,padx=10,pady=5)
e1.grid(row=8,column=1,padx=10,pady=5)


def select(): # 实现浏览按钮3的功能
    filename = tkinter.filedialog.askopenfilename()
    if filename != "":
        e1.delete(0,END)
        e1.insert(0,filename)

Button(win,text="爬取评论",width=10,command=barch_spider_comment).grid(row=2,column=2,padx=10,pady=5)

Button(win,text="浏览",width=10,command=select).grid(row=3,column=2,padx=10,pady=5)

Button(win,text="生成词频统计图",width=10,command=get_wordtxt).grid(row=4,column=1,padx=10,pady=5)

Button(win,text="生成词云图",width=10,command=get_wordcloud).grid(row=5,column=1,padx=10,pady=5)


win.mainloop()# 进入消息循环
