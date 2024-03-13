fo = open('商品目录.txt', 'a', encoding='utf-8')
a=input('')
com={a:["大学物理练习册",36]}
# fo.next()
fo.write(str(com))
fo.close()

fi = open('商品目录.txt', 'r', encoding='utf-8')
txt = fi.readlines()
fi.close()
print(str(txt))
