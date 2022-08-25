while True:
	chars = input().split()
	if chars[0] == '-':
		break
	else:
		ans = 0
		for ch in chars:
			ans += ord(ch)-96
			if(ans > 26):
				ans -= 26
	print(chr(ans+96))
