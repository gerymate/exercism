class Isogram
    def self.isogram? word
        letters = {}
        word.scan(/\w/) do |letter|
            letter = letter.upcase
            letters[letter] ||= 0
            letters[letter] += 1
        end
        letters.all? {|_,num| num<2}
    end
end