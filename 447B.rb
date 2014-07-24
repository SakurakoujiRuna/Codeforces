s = gets.chomp
k = gets.to_i
w = gets.split.map { |x| x.to_i }

ans = 0
s.each_char.with_index do |c, i|
	ans += w[c.ord - 97] * (i + 1)
end
ans += k * (s.length + 1 + s.length + k) / 2 * w.max

puts ans
