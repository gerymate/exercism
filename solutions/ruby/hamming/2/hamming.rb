class Hamming
  def self.compute(first_string, second_string)
    raise ArgumentError if first_string.size != second_string.size

    first_string.chars.zip(second_string.chars).count {|ch1, ch2| ch1 != ch2}
  end
end