import requests as r
import json as j

token = input("Please input your token: ")

for i in range(5413309300, 5413323716):
	post = r.post("https://v1-c.wqketang.com/resource/download?token=%s" % token, data = {"resourceId": i})
#	print("https://v1-c.wqketang.com/resource/download?token=%s" % token)
	try:
		print(post.text)
		play = j.loads(post.text)["data"]['PlayAuth']
		if(play.find("算法竞赛") == -1):
			continue
		else:
			print(play)
		get = r.get(play)
		file = open("saves/%s.mp4" % play[play.find("算法竞赛"):play.find(".mp4")], "wb");
		file.write(get.content)
		file.close()
		print(i)
	except (KeyError, TypeError):
		pass
