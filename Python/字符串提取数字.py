import re
string='https://item.jd.com/123456789a.html'
s = re.findall(r"https://item.jd.com/\d+.html", string)
#print(len(s))
#print(s)
if re.match(r"https://item.jd.com/\d+.html", string) is None:
    print(1)
else:
    print(2)