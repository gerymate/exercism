class Robot
  attr_reader :name

  def self.forget
    @@free_names = ('AA000'..'ZZ999').to_a.shuffle!
  end

  forget

  def initialize
    @name = @@free_names.shift
  end
  
  def reset
    @@free_names << @name
    @name = @@free_names.shift
  end
end
