class Luhn
  def self.valid?(code_string)
    return false unless code_string =~ /^[[[:digit:]][[:blank:]]]+$/
    code = code_string.chars.select {|ch| ch =~ /[[:digit:]]/}.map(&:to_i)
    return false if code.length <= 1

    code.size.times do |i|
      if i.even?
        code[-i] *= 2
        code[-i] -= 9 if code[-i] > 9
      end
    end

    (code.sum % 10).zero?
  end

end