s=input()
news=""
for i in s:
    if ord(i)>= 65 and ord(i)<=91:
        news+=chr(ord(i)-65+97)
    else:
        news+=chr(ord(i)-97+65)
print(news)
