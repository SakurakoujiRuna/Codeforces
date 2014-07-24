p, n = gets.split.map { |x| x.to_i }
vis = Array.new(p, false)

ans = -1
n.times do |i|
	x = gets.to_i % p
	if !vis[x] ;
		vis[x] = true
	elsif ans == -1 ;
		ans = i+1;
	end
end
puts ans
