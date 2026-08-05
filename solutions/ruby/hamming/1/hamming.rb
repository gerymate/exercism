class Hamming
  def self.compute(string_A, string_B)
    raise ArgumentError if string_A.size != string_B.size
    hamming = 0
    string_A.each_char.with_index do
      |ch, i| hamming += 1 if ch != string_B[i]
    end
    hamming
  end
end