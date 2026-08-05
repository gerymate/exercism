class Robot
  attr_reader :name

  def self.generate_all_names
    ('AA000'..'ZZ999').to_a.shuffle!
  end

  @@free_names = generate_all_names

  def self.forget
    @@free_names = generate_all_names
  end

  
  def initialize
    @name = @@free_names.shift
  end
  
  def reset
    @@free_names << @name
    @name = @@free_names.shift
  end
end
