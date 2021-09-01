from snownlp import *
text1 = '真心棒，太完美了'
text2 = '烂烂烂烂烂'
s1 = SnowNLP(text1)
s2 = SnowNLP(text2)
print(s1.sentiments,s2.sentiments)