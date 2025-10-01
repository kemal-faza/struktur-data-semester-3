def SearchJadwal(hari: str, awal: int, akhir: int) -> str:
    if hari == "sen":
        if awal < 15 and akhir > 13:
            return "Dasar Pemrograman"
    elif hari == "sel":
        if awal < 15 and akhir > 13:
            return "Aljabar Linier"
    elif hari == "rab":
        if awal < 10 and akhir > 7:
            if awal < 16 and akhir > 15:
                return "Dasar Sistem & Bahasa Inggris I"
            return "Dasar Sistem"
        elif awal < 16 and akhir > 15:
            return "Bahasa Inggris I"
    elif hari == "kam":
        if awal < 9 and akhir > 7:
            if awal < 15 and akhir > 13:
                return "Pancasila & Matematika I"
            return "Pancasila"
        elif awal < 15 and akhir > 13:
            return "Matematika I"
    elif hari == "jum":
        if awal < 9 and akhir > 7:
            if awal < 16 and akhir > 13:
                return "Bahasa Indonesia & Struktur Diskrit"
            return "Bahasa Indonesia"
        elif awal < 16 and akhir > 13:
            return "Struktur Diskrit"
    return "Tidak ada"
