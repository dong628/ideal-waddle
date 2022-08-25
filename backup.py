import os
import os.path as p
import time as t

pwd = "/extra/Backups";
os.chdir(pwd); os.system("pwd");
files = os.listdir();
earlist = p.getmtime(files[0]);
tar = files[0];

for file in files:
#	print(file, p.getmtime(file), sep="\t");
	if(earlist > p.getmtime(file)):
		earlist = p.getmtime(file);
		tar = file;

# print("-----")
# print(tar, earlist, sep="\t");

# os.system("cp %s %s.bak"%(tar, tar));
# os.system("dd if=/dev/nvme0n1p2 of=%s")


fname = t.strftime("%Y%m%d_root.img");

os.system("echo Generating backup %s. >> /dev/pts/0"%fname);
# print("dd if=/dev/nvme0n1p2 of=%s"%fname);
resdd = os.system('kdesu --noignorebutton -c "dd if=/dev/nvme0n1p2 of=%s >> backup.log"'%fname);
if resdd == 0:
	os.system("echo Removing %s >> /dev/pts/0"%tar);
	os.system('kdesu --noignorebutton -c "rm %s"'%tar);
# print("rm %s"%tar);
# os.system("sleep 2");
	os.system("echo New backup %s. >> /dev/pts/0"%fname);
else:
	os.system("echo Interrupted! >> /dev/pts/0");
