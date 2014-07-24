n, m = gets.split.map { |x| x.to_i }
need = gets.split.map.with_index { |x, i| [(x.to_i+m-1)/m, i+1] }
puts need.max[1]
