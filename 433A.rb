n = gets.to_i
f = gets.split.map { |x| x.to_i }

sum = 0
flag = false

f.each do |x|
	sum += x
	if x == 100 ;
		flag = true
	end
end

if sum % 200 == 100 ;
	print "NO\n"
elsif sum % 400 == 200 && !flag ;
	print "NO\n"
else
	print "YES\n"
end
