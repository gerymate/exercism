class Clock
  attr_reader :hour, :minute

  def initialize(hour: 0, minute: 0)
    total_minutes = hour * 60 + minute
    total_hours = total_minutes / 60
    @hour = total_hours % 24
    @minute = total_minutes - 60 * total_hours
  end

  def +(rhs)
    Clock.new(hour: @hour + rhs.hour, minute: @minute + rhs.minute)
  end

  def -(rhs)
    Clock.new(hour: @hour - rhs.hour, minute: @minute - rhs.minute)
  end

  def ==(rhs)
    @hour == rhs.hour && @minute == rhs.minute
  end

  def to_s
    "%02d:%02d" % [@hour, @minute]
  end
end
