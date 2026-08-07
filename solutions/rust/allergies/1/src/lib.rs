pub struct Allergies(u32);

#[derive(Debug, PartialEq, Eq, Copy, Clone)]
pub enum Allergen {
    Eggs = 1,
    Peanuts = 2,
    Shellfish = 4,
    Strawberries = 8,
    Tomatoes = 16,
    Chocolate = 32,
    Pollen = 64,
    Cats = 128,
}

impl Allergies {
    pub fn new(score: u32) -> Self {
        Allergies(score)
    }

    pub fn is_allergic_to(&self, allergen: &Allergen) -> bool {
        let test = (*allergen) as u32;
        (self.0 & test) != 0
    }

    pub fn allergies(&self) -> Vec<Allergen> {
        use Allergen::*;
        let mut allergens = vec![
            Eggs,
            Peanuts,
            Shellfish,
            Strawberries,
            Tomatoes,
            Chocolate,
            Pollen,
            Cats,
        ];
        allergens.retain(|allergen| self.is_allergic_to(allergen));
        allergens
    }
}
