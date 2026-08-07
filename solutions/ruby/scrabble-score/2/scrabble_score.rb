class Scrabble
  private def self.get_char_score ch
    case ch
    when /\s/ then 0
    when /[AEIOULNRST]/i then 1
    when /[DG        ]/i then 2
    when /[BCMP      ]/i then 3
    when /[FHVWY     ]/i then 4
    when /[K         ]/i then 5
    when /[JX        ]/i then 8
    when /[QZ        ]/i then 10
    else 0
    end
  end
  
  def self.score word
    return 0 if word.nil? or word.empty? 
    word.chars.reduce(0) { |sum, ch| sum += get_char_score(ch) }
  end
  
  def initialize word
    @word = word
  end

  def score
    Scrabble.score @word
  end
end