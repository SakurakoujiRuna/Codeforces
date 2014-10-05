n, p, k = gets.split.map { |x| x.to_i }

if p-k > 1 ;
	print ?<, ?<, ' '
end

(p-k).upto(p+k) do |i|
	if i == p ;
		print ?(, i, ?), ' '
	elsif i >= 1 && i <= n ;
		print i, ' '
	end
end

if p+k < n ;
	print ?>, ?>, ' '
end

print ?\n
