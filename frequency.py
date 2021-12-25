try:
	import openpyxl as x
	from openpyxl.chart import BarChart, Series, Reference
except ModuleNotFoundError:
	print("检测到未安装openpyxl库，将输出result.txt文档");
	mode = 0;
else:
	print("已安装openpyxl库，输出文件为result.xlsx表格文档");
	mode = 1;


Filename = input("请输入要统计的文档名称（包括拓展名）：");

def excel(filename):
	wb = x.Workbook();
	sheet = wb.active;
	sheet.title = "sheet1"

	with open(filename, "r") as f:
		a = f.read();
		l = list();
		for i in range(26):
			l.append(0);
		for i in a:
			if ord(i.lower())>=ord("a") and ord(i.lower())<=ord("z"):
				l[ord(i.lower())-ord("a")]+=1;

	sheet["A1"] = "字母";
	sheet["B1"] = "出现次数";
	for i in range(26):
		sheet["A"+str(i+2)] = chr(ord("a")+i);
		sheet["B"+str(i+2)] = l[i];

	chart = BarChart();
	chart.type = "col";
	chart.style = 10;
	chart.title = "%s 中各字母出现次数" % filename;
	chart.y_axis.title = '出现次数';
	chart.x_axis.title = '字母';
	data = Reference(sheet, min_col=2, min_row=1, max_row=27, max_col=2);
	cats = Reference(sheet, min_col=1, min_row=2, max_row=27);
	chart.add_data(data, titles_from_data=True);
	chart.set_categories(cats);
	chart.shape = 4;
	sheet.add_chart(chart, "C1");
	
	wb.save("result.xlsx");

def text(filename):
	with open(filename, "r") as f:
		a = f.read();
		l = list();
		for i in range(26):
			l.append(0);
		for i in a:
			if i.isalpha() and ord(i.lower())>=ord("a") and ord(i.lower())<=ord("z"):
				l[ord(i.lower())-ord("a")]+=1;
	
	with open("result.txt", "w") as f:
		for i in range(26):
			f.write(chr(ord("a")+i)+" ");
			f.write(str(l[i]));
			f.write("\n");

if mode == 0:
	text(Filename);
else:
	excel(Filename);
