import os

main = open("1984.out", 'r');
for name in range(126):
	f = open("sdks/%d.in"%name, 'w');
	for i in range(10):
		f.writelines(main.readline());
	f.close()
	os.system("cat sdks/%d.in | ./solve >> result"%name);
