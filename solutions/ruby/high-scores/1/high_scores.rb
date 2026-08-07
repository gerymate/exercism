class HighScores
  attr_reader :scores

  def initialize(score_data)
    @scores = score_data
  end

  def latest
    @scores.last
  end

  def personal_best
    @scores.max
  end

  def personal_top
    @scores.max(3)
  end

  def report
    last = latest
    diff = personal_best - last
    if diff.zero?
      "Your latest score was #{last}. That's your personal best!"
    else      
      "Your latest score was #{last}. That's #{diff} short of your personal best!"
    end
  end
end