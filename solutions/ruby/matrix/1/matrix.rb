
class Matrix
  attr_reader :rows, :columns
  def initialize data
    rowstrings = data.split("\n")
    @rows = rowstrings.map do |rowdata|
      rowdata.split.map {|item| item.to_i}
    end
    
    @columns = []
    @rows[0].each { |_| @columns << [] }
    @columns.each_with_index do |col, index|
      @rows.each do |row|
        col << row[index]
      end
    end
  end     
end
