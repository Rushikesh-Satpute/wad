import { HttpClient } from '@angular/common/http';
import { Component } from '@angular/core';
import { Router } from '@angular/router';

@Component({
  selector: 'app-login',
  templateUrl: './login.component.html',
  styleUrls: ['./login.component.css']
})
export class LoginComponent {


  loginObj: any = {
    "EmailId": "",
    "Password": ""
  };
  constructor(private http: HttpClient, private router: Router) { }

  onLogin() {
    debugger;
    alert('login Success');
    this.router.navigateByUrl('/dashboard');
  }


}

