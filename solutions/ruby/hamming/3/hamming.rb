class Hamming
  def self.compute(first_string, second_string)
    raise ArgumentError if first_string.size != second_string.size
    0.upto(first_string.size).count {|i| first_string[i] != second_string[i]}
  end
end