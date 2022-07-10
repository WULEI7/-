import re
value=[]
password=input().split(",")
for p in password:
    if  len(p)<6 or len(p)>12:
        continue
    if  not re.search("[a-z]",p):
        continue
    elif  not re.search("[A-Z]",p):
        continue
    elif  not re.search("[0-9]",p):
        continue
    elif not  re.search("[!#@]",p):
        continue
    value.append(p)
print(",".join(str(i) for i in value))
