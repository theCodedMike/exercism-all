#include "protein_translation.h"

namespace protein_translation {
    std::string codon2protein(std::string_view codon) {
        if (codon == "AUG")
            return "Methionine";
        if (codon == "UUU" || codon == "UUC")
            return "Phenylalanine";
        if (codon == "UUA" || codon == "UUG")
            return "Leucine";
        if (codon == "UCU" || codon == "UCC" || codon == "UCA" || codon == "UCG")
            return "Serine";
        if (codon == "UAU" || codon == "UAC")
            return "Tyrosine";
        if (codon == "UGU" || codon == "UGC")
            return "Cysteine";
        if (codon == "UGG")
            return "Tryptophan";
        if (codon == "UAA" || codon == "UAG" || codon == "UGA")
            return "STOP";
        return "";
    }

    std::vector<std::string> proteins(std::string_view codons) {
        std::vector<std::string> result;

        for (std::size_t i = 0; i < codons.size(); i += 3) {
            auto protein = codon2protein(codons.substr(i, 3));
            if (protein == "STOP")
                break;
            result.push_back(protein);
        }

        return result;
    }
}  // namespace protein_translation
