class Squares
  def initialize number
    @number = number
  end

  def square_of_sum
    sum = (1..@number).inject(0, &:+)
    sum * sum
  end

  def sum_of_squares
    (1..@number).map{|n| n * n}.inject(0, &:+)
  end

  def difference
    square_of_sum - sum_of_squares
  end
end