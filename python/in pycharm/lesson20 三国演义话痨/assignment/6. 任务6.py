# -*- coding:utf-8 -*-
# 新知识点：学习使用第三方库实现数据呈现
# 需要安装pyecharts

from pyecharts.charts import Bar, Line, Pie

# 柱状图
x_data = ['1月', '2月', '3月', '4月', '5月', '6月']
y_data = [123, 153, 89, 107, 98, 23]
Bar().add_xaxis(x_data).add_yaxis('降水量/mm', y_data).render("my柱状图.html")
# 折线图
x_data1 = ['12日', '13日', '14日', '15日', '16日', '17日']
y_data1 = [23, 21, 22, 25, 23.5, 19]
Line().add_xaxis(x_data1).add_yaxis('2022气温℃', y_data1).render("折线图.html")
# 饼状
cate = ['社会', '地理', '量子力学', '轨迹', '电子信息', '高分子']
data = [123, 153, 89, 107, 98, 23]
Pie().add('', [list(z) for z in zip(cate, data)], is_label_show=True).render("my饼状图.html")
