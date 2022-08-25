from PIL import Image as img

f = open("1814.out", "r");
image = img.new(mode="RGB", size=(27, 27), color="white");
for i in range(27):
	line = f.readline();
	for j in range(27):
		if line[j]=='1':
#			image.putpixel((i, j), (255, 255, 255));
			image.putpixel((i, j), (0, 0, 0));

f.close();
image.show();
