# ��֪ʶ��1��������ʽ��ͨ�����
# ��֪ʶ��2���ļ�ָ���붨λ
# ���߼���1��ѧϰ�����ļ��ڴ�ͼ��2����⡰utf-8������ANSI�������ʽ
import re
li=re.findall('".*?"', 'hello�����ǡ�, Ϊ���β���"��"�Գ�"������ʦ"��super���Գ�"�칫����"���ű���"�ع�����"��fdsf��fs��')
#.��ʾ����1���ַ���*��ʾ0-N���ַ���?��ʾ"XXXXX"��ʽֻƥ��1��
print(li)

for i in range(len(li)):
    li[i]=li[i].replace('"','')
print(li)



fi = open('data7.txt', 'r', encoding='utf-8')
a = []

for i in range(11):
    a.append(fi.readline())
    print(a)
    print(fi.tell())

with open('record.txt', 'w', encoding='utf-8') as file:
    for line in a:
        file.write(line)
        file.writelines("\n")
        file.tell()

#
# a.append(fi.read(1))
# print(fi.tell())
# a.append(fi.read(2))
# print(fi.tell())
# a.append(fi.read(3))
# print(fi.tell())
# print(a)
#
# for i in range(3):
#     a.append(fi.readline())
#     print(a)
#     print(fi.tell())

