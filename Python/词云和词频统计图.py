import os
import re
import PIL
import wordcloud
import matplotlib.pyplot as plt
from wordcloud import WordCloud
import numpy as np
import jieba.analyse
from collections import Counter

#plt.rcParams['font.sans-serif'] = [u'SimHei']
#plt.rcParams['axes.unicode_minus'] = False


def stopwordslist():
    stopwords = [line.strip() for line in open('Stopword.txt', encoding='UTF-8').readlines()]
    print(stopwords)
    #return stopwords

def get_plt():
    words_str = ""
    with open("jd_comment.txt") as f:
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
    ax.barh(range(len(x)), y, color='gold')
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
    words_str = ""
    with open("jd_comment.txt") as f:
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
    image_colors = wordcloud.ImageColorGenerator(mask)  # 可以去掉 # 基于彩色图像生成相应彩色 文字颜色跟随背景图颜色
    wc.recolor(color_func=image_colors)
    wc.to_file("词云.jpg")
    #plt.imshow(wc)
    #plt.axis('off')
    #plt.show()

stopwordslist()
#get_plt() #词频统计图生成
#get_wordcloud()  # 词云生成