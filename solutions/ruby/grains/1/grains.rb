class Grains
  def self.square(n)
    raise ArgumentError unless (1 <= n) and (n <= 64)
    2 ** (n - 1) # a cleaner version
    # 1 << (n - 1) # a faster version
  end

  def self.total
    (2 ** 64) - 1 # a cleaner version
    # (1 << 64) - 1 # a faster version
  end
end