x, y = gets.split.map { |x| x.to_i }

n = gets.to_i % 6 + 5

n.times do
	x, y = y, y - x
end
MOD = 1000000007
puts (x % MOD + MOD) % MOD
