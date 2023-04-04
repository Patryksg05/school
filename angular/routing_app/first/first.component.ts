import { Component } from '@angular/core';
import { Router, ActivatedRoute, ParamMap } from '@angular/router';

@Component({
  selector: 'app-first',
  templateUrl: './first.component.html',
  styleUrls: ['./first.component.css']
})

export class FirstComponent {
  name: any;
  fruits: Fruit[] = [new Fruit('apple', 5),
    new Fruit('banana', 10),
    new Fruit('orange', 12),
    new Fruit('pineapple', 15),
    new Fruit('ananas', 22),
    new Fruit('a', 2),
    new Fruit('Watermelon', 19)];

  count:number = this.fruits.length;

  constructor(
    private route: ActivatedRoute,
  ) {}

  ngOnInit() {
    this.route.queryParams.subscribe(params => {
      this.name = params['name'];
    });
  }

}

class Fruit {
  n_fruit: string;
  price_fruit: number;

  constructor(n:string, p: number)
  {
    this.n_fruit = n;
    this.price_fruit = p;
  }
}

/**
 * Po kliknięciu w zakładkę pierwszego komponentu
 * (frist komponent) powinna wyświetlić się lista numerowana,
 * pole, które zlicza ilość elementów listy i ją wyświetla.
 * Lista powinna składać się z nazw owoców.
 * Po kliknieciu zakładki drugiego komponentu
 * (second komponent)
 * powinien wyświetlić nam się formularz (ngForm),
 * który zawiera pola: imię i nazwisko, e-mail oraz przycisk "wyślij",
 * który aktywuje się dopiero po wypełnieniu wszyskich pól formularza.
 * Powinien pokazywać się też napis "pole wymagane",
 * gdy klikniemy dane pole, ale go nie wypełnimy.
 */
