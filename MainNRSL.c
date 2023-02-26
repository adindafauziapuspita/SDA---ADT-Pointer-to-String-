/* File        : mainNRSL.cpp */
/* Deskripsi   : Driver / main program untuk ADT Non Restricted Single Linked/Linear List */
/* Dibuat oleh : Ade Chandra Nugraha*/
/* Tanggal     : 25-10-2001 */
/* Diupdate oleh : Santi Sundari, 6-4-2011, hanya tdd operasi2 dasar */

#include "bodynrsl.cpp"
#include "spnrsll.h"
#include <stdio.h>

int main()
{
	/* Kamus Lokal */
		List MyList, List2, List3;
		infotype isi;
		address P, Prec;

	/* Program */
	CreateList (&MyList);
/* Menambah List di awal */
	InsVFirst(&MyList, "five");
	InsVFirst(&MyList, "four");
	InsVFirst(&MyList, "three");
	InsVFirst(&MyList, "two");
	InsVFirst(&MyList, "one");
	printf ("Hasil InsVFirst 5 x adalah : "); PrintInfo (MyList);

/* Mencari suatu elemen di list */

	P = Search(MyList, "two");
	printf ("Search yang berhasil (two) : P = %p, Ketemu = %d \n",P,FSearch(MyList,P));
	DelP (&MyList, "two");
	printf ("Hasil hapus elemen (two): ");
	PrintInfo (MyList);

/* Insert di Last */
	printf ("Insert di akhir nilai six : ");
	InsVLast (&MyList, "six");
	PrintInfo (MyList);

/* Insert diantara 2 elemen */
	printf ("Insert sebelum elemen three  : ");
	Prec = SearchPrec (MyList, "three");
	P = Alokasi ("two");
	if (P != Nil)
	{   InsertAfter (&MyList, P, Prec);	}
	PrintInfo (MyList);

/* Menghapus elemen List */
	printf ("Hasil Delete dari elemen List :\n");
	DelVFirst (&MyList, &isi);
	printf ("DelVFirst adalah %s\t", isi);

	DelVLast (&MyList, &isi);
	printf ("DelVLast adalah %s\t", isi);

/* Menghapus elemen di tengah-tengah */
	Prec = SearchPrec (MyList, "four");	/* Node yang akan dihapus */
	if (Prec != Nil)
	{
		 DelAfter (&MyList, &P, Prec);
		 isi = Info(P);
		 DeAlokasi (P);
		 printf ("DelAfter adalah %s\n", isi);
	}
	printf ("Hasil setelah delete : ");
		  PrintInfo (MyList);

	printf ("Insert sebelum elemen five : ");
	Prec = SearchPrec (MyList, "five");
	P = Alokasi ("empat");
	if (P != Nil)
	{   InsertAfter (&MyList, P, Prec);	}
	PrintInfo (MyList);

/* Finishing */
	P = First(MyList);
	DeAlokasi (P);
	P = First(List2);
	DeAlokasi (P);
	P = First(List3);
	DeAlokasi (P);
	return 0;
}