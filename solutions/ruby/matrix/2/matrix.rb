class Matrix
  attr_reader :rows, :columns

  def initialize textual_data
    @rows = textual_data.lines.map do |data_for_a_row|
      data_for_a_row.split.map(&:to_i)
    end
    
    @columns = @rows.transpose
  end     
end
