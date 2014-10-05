n = gets.to_i
n.times do
	s = ?0 + gets
	ans = []
	1.upto(12) do |i|
		if 12 % i == 0 ;
			flag = false
			1.upto(12/i) do |j|
				tflag = true
				1.upto(i) do |k|
					if s[(k-1)*(12/i)+j] == ?O ;
						tflag = false;
					end
				end
				flag = true if tflag == true
			end
			ans << i if flag == true
		end
	end
	print ans.size
	ans.each do |x|
		print ' ', x, ?x, 12/x
	end
	print ?\n
end