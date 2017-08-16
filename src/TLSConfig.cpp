#include "MQTTClient.h"

namespace MQTT {

char MQTTClient::DEFAULT_SSL_CA_PEM[] =
    "-----BEGIN CERTIFICATE-----\n"
    "MIIFEzCCA/ugAwIBAgISAx+UEx6zhyIn7JaQvGgVWaLzMA0GCSqGSIb3DQEBCwUA\n"
    "MEoxCzAJBgNVBAYTAlVTMRYwFAYDVQQKEw1MZXQncyBFbmNyeXB0MSMwIQYDVQQD\n"
    "ExpMZXQncyBFbmNyeXB0IEF1dGhvcml0eSBYMzAeFw0xNzA2MjYwNTU0MDBaFw0x\n"
    "NzA5MjQwNTU0MDBaMCMxITAfBgNVBAMTGG1xdHQuZGV2Lmthc3BlcndvcmxkLmNv\n"
    "bTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAKai6Zu1vXzdgBiVlF/d\n"
    "SnYUImojX2uulD+WNeThlP619EWQfN1O2bUXkXpx65kyzeMrQezOvGqJI5XcAKaO\n"
    "uYWKDLjFwgOXUqz6Vckz3/7yn+w3d1F+2bArBMf4HDiDzbZJx1BaWCGGA+0x+kmP\n"
    "2ZKqK7vmaRRi9T3QQ3JluQpPF7B9cV49g3APDIBpg+TG6L64tsWCNbrDvbpDmKLl\n"
    "jCUgfPzbKdktlqI4cPxFORgK4uNbrnUiKZrAP+TOdIoICawr+Vh8WJesbayU8Fri\n"
    "IOQC9CCRRaRV5vZgBE8esXo7/IYkuHBGFj6bATVqDt/ftAQ6Xi53dngfhpJAyAV/\n"
    "iG0CAwEAAaOCAhgwggIUMA4GA1UdDwEB/wQEAwIFoDAdBgNVHSUEFjAUBggrBgEF\n"
    "BQcDAQYIKwYBBQUHAwIwDAYDVR0TAQH/BAIwADAdBgNVHQ4EFgQUrt+RYQkYLemP\n"
    "/YWv5FlKlSmwdXEwHwYDVR0jBBgwFoAUqEpqYwR93brm0Tm3pkVl7/Oo7KEwbwYI\n"
    "KwYBBQUHAQEEYzBhMC4GCCsGAQUFBzABhiJodHRwOi8vb2NzcC5pbnQteDMubGV0\n"
    "c2VuY3J5cHQub3JnMC8GCCsGAQUFBzAChiNodHRwOi8vY2VydC5pbnQteDMubGV0\n"
    "c2VuY3J5cHQub3JnLzAjBgNVHREEHDAaghhtcXR0LmRldi5rYXNwZXJ3b3JsZC5j\n"
    "b20wgf4GA1UdIASB9jCB8zAIBgZngQwBAgEwgeYGCysGAQQBgt8TAQEBMIHWMCYG\n"
    "CCsGAQUFBwIBFhpodHRwOi8vY3BzLmxldHNlbmNyeXB0Lm9yZzCBqwYIKwYBBQUH\n"
    "AgIwgZ4MgZtUaGlzIENlcnRpZmljYXRlIG1heSBvbmx5IGJlIHJlbGllZCB1cG9u\n"
    "IGJ5IFJlbHlpbmcgUGFydGllcyBhbmQgb25seSBpbiBhY2NvcmRhbmNlIHdpdGgg\n"
    "dGhlIENlcnRpZmljYXRlIFBvbGljeSBmb3VuZCBhdCBodHRwczovL2xldHNlbmNy\n"
    "eXB0Lm9yZy9yZXBvc2l0b3J5LzANBgkqhkiG9w0BAQsFAAOCAQEAcxCPFLCZqDrm\n"
    "02h+CxP+2xuikfZeEzVhu0DvzOl6/7cmUdKfNB3k8GtVo+xLpVyoI0Yv1VL9kOw2\n"
    "xxPLp5pBUvHxXn+xBdV5j+Y24VXc7rprk30158kvAyCAyCgMNZxQt7cRmW6h/mfp\n"
    "TahPaZP7cWJUGx85vG8BaIn99iN3O8Wh1/uvc5Wz2VBSlaWMQXInUWmaB3enRR5A\n"
    "8j1Z8XoE6OSgtuYoJ/lwB/OJNZloQK8sblP0U/w4BsqOT6pQhguvvFbdWRgzF6Du\n"
    "AQzXJlszs9+G0kMZgJFkCf6bPWjh1TSrff+LDrKrxVePaG72J33OzLve1yVj4qS+\n"
    "UsPRATd8EA==\n"
    "-----END CERTIFICATE-----\n"
    "-----BEGIN CERTIFICATE-----\n"
    "MIIEkjCCA3qgAwIBAgIQCgFBQgAAAVOFc2oLheynCDANBgkqhkiG9w0BAQsFADA/\n"
    "MSQwIgYDVQQKExtEaWdpdGFsIFNpZ25hdHVyZSBUcnVzdCBDby4xFzAVBgNVBAMT\n"
    "DkRTVCBSb290IENBIFgzMB4XDTE2MDMxNzE2NDA0NloXDTIxMDMxNzE2NDA0Nlow\n"
    "SjELMAkGA1UEBhMCVVMxFjAUBgNVBAoTDUxldCdzIEVuY3J5cHQxIzAhBgNVBAMT\n"
    "GkxldCdzIEVuY3J5cHQgQXV0aG9yaXR5IFgzMIIBIjANBgkqhkiG9w0BAQEFAAOC\n"
    "AQ8AMIIBCgKCAQEAnNMM8FrlLke3cl03g7NoYzDq1zUmGSXhvb418XCSL7e4S0EF\n"
    "q6meNQhY7LEqxGiHC6PjdeTm86dicbp5gWAf15Gan/PQeGdxyGkOlZHP/uaZ6WA8\n"
    "SMx+yk13EiSdRxta67nsHjcAHJyse6cF6s5K671B5TaYucv9bTyWaN8jKkKQDIZ0\n"
    "Z8h/pZq4UmEUEz9l6YKHy9v6Dlb2honzhT+Xhq+w3Brvaw2VFn3EK6BlspkENnWA\n"
    "a6xK8xuQSXgvopZPKiAlKQTGdMDQMc2PMTiVFrqoM7hD8bEfwzB/onkxEz0tNvjj\n"
    "/PIzark5McWvxI0NHWQWM6r6hCm21AvA2H3DkwIDAQABo4IBfTCCAXkwEgYDVR0T\n"
    "AQH/BAgwBgEB/wIBADAOBgNVHQ8BAf8EBAMCAYYwfwYIKwYBBQUHAQEEczBxMDIG\n"
    "CCsGAQUFBzABhiZodHRwOi8vaXNyZy50cnVzdGlkLm9jc3AuaWRlbnRydXN0LmNv\n"
    "bTA7BggrBgEFBQcwAoYvaHR0cDovL2FwcHMuaWRlbnRydXN0LmNvbS9yb290cy9k\n"
    "c3Ryb290Y2F4My5wN2MwHwYDVR0jBBgwFoAUxKexpHsscfrb4UuQdf/EFWCFiRAw\n"
    "VAYDVR0gBE0wSzAIBgZngQwBAgEwPwYLKwYBBAGC3xMBAQEwMDAuBggrBgEFBQcC\n"
    "ARYiaHR0cDovL2Nwcy5yb290LXgxLmxldHNlbmNyeXB0Lm9yZzA8BgNVHR8ENTAz\n"
    "MDGgL6AthitodHRwOi8vY3JsLmlkZW50cnVzdC5jb20vRFNUUk9PVENBWDNDUkwu\n"
    "Y3JsMB0GA1UdDgQWBBSoSmpjBH3duubRObemRWXv86jsoTANBgkqhkiG9w0BAQsF\n"
    "AAOCAQEA3TPXEfNjWDjdGBX7CVW+dla5cEilaUcne8IkCJLxWh9KEik3JHRRHGJo\n"
    "uM2VcGfl96S8TihRzZvoroed6ti6WqEBmtzw3Wodatg+VyOeph4EYpr/1wXKtx8/\n"
    "wApIvJSwtmVi4MFU5aMqrSDE6ea73Mj2tcMyo5jMd6jmeWUHK8so/joWUoHOUgwu\n"
    "X4Po1QYz+3dszkDqMp4fklxBwXRsW10KXzPMTZ+sOPAveyxindmjkW8lGy+QsRlG\n"
    "PfZ+G6Z6h7mjem0Y+iWlkYcV4PIWL1iwBi8saCbGS5jN2p8M+X+Q7UNKEkROb3N6\n"
    "KOqkqm57TH2H3eDJAkSnh6/DNFu0Qg==\n"
    "-----END CERTIFICATE-----\n";
// "-----BEGIN CERTIFICATE-----\n"
// "MIIGRzCCBC+gAwIBAgIJANu7Ilp9OlmEMA0GCSqGSIb3DQEBCwUAMIGxMQswCQYD\n"
// "VQQGEwJMSzEQMA4GA1UECAwHV2VzdGVybjEQMA4GA1UEBwwHQ29sb21ibzEWMBQG\n"
// "A1UECgwNS2FzcGVyIEdsb2JhbDEjMCEGA1UECwwaU2VydmVyIFJlc2VhcmNoIERl\n"
// "cGFydG1lbnQxGzAZBgNVBAMMEmNhLmthc3BlcndvcmxkLmNvbTEkMCIGCSqGSIb3\n"
// "DQEJARYVYWRtaW5Aa2FzcGVyd29ybGQuY29tMB4XDTE3MDYyNjA5NDY0MVoXDTE3\n"
// "MDcyNjA5NDY0MVowgbExCzAJBgNVBAYTAkxLMRAwDgYDVQQIDAdXZXN0ZXJuMRAw\n"
// "DgYDVQQHDAdDb2xvbWJvMRYwFAYDVQQKDA1LYXNwZXIgR2xvYmFsMSMwIQYDVQQL\n"
// "DBpTZXJ2ZXIgUmVzZWFyY2ggRGVwYXJ0bWVudDEbMBkGA1UEAwwSY2Eua2FzcGVy\n"
// "d29ybGQuY29tMSQwIgYJKoZIhvcNAQkBFhVhZG1pbkBrYXNwZXJ3b3JsZC5jb20w\n"
// "ggIiMA0GCSqGSIb3DQEBAQUAA4ICDwAwggIKAoICAQDdDZEY1mwFpoL3M2ymHZOG\n"
// "HoEhoqwwGfEhZPRkkAlhRDXXC9+ZkexIPJn3gI/twBct1dlyqNXRyZUAAWOZv7e4\n"
// "9W6Gtujd84m6Bk64yAjOB3bJRkV2EKmPR4iaOX+G2mNXyRNpBV9oJ6VsOzA4P8DB\n"
// "megCO7xM9b4Hhccb0jChQYEuUhfyS1Yu6fQPTSrK6Hqb9fa6UmMayncOzq2SKzfb\n"
// "wfpFYDeL8/K8356WlkWr48FCa/kKWsDtI/vqM508dJH4kwaHZ7mxfsWB0xmelUfz\n"
// "CtV/Qo5fReuV0wZbiq5L9STerhNWUMNotvfPz5LKacW1qnbf+1LjoHpQlYMG5uBL\n"
// "0eqZTspciSgW+WMRcXcbuhaJa/WXwmBZVabHaiACIt5KO7JUXTozrAeQXReG8ZML\n"
// "44prsBIpVYSt4Xo80Pq8aBToDi7DpDXMcvm/6xuMOT8k/1x15AWk7UMEyDHV8e7R\n"
// "edCz28rOsjz/X50FCq+JhQTZRRVHX6KajX2VhCoL4IrsL1H17MNUeQ5MU6ll30On\n"
// "NpLhD8JoUYRcWYsAm99G9FSYuKu+CrArEUHlyspb8xRRhUCQGMvYX0fqHnMR80rV\n"
// "n5UjeFtQ0qvoTpQ+tmpDnfAsOzN/bcIHo8a9hvbBHKflMbh0XLArVf4OKDEmQrZ5\n"
// "IlnaLTUW8c5jBEUumcktbQIDAQABo2AwXjAdBgNVHQ4EFgQUlKXjuHdmSPPlqJpn\n"
// "LbPnlojxhbowHwYDVR0jBBgwFoAUlKXjuHdmSPPlqJpnLbPnlojxhbowDwYDVR0T\n"
// "AQH/BAUwAwEB/zALBgNVHQ8EBAMCAQYwDQYJKoZIhvcNAQELBQADggIBAH+icvYC\n"
// "HOlR9QHKMtRw6vNGwoONVv+gL5FrGYFw9U/KVxs8rBWX8vcExhhehYv4eeYDM61q\n"
// "IaXhyFOnRHzDRVOFR7nDOo+2nBBnVyEMVETl9+27MMIDlLLa4j6XtQ4G9TjhcXvt\n"
// "5+yKZT907ZRDxkbumwvFyA3FidlSkNrlegBknvO7ZXmMccoEhN4HT8YywB/HNU03\n"
// "8NiyaC4Dlr/NbDocJvCDoqbTjiq1nLu4h5c4Sc0DhRWpyp38cXX5GH7mJmqVoPgX\n"
// "2/aLZoYcdJEg7ws9u5Sa1M5mQroqdCwUb5bsTS0EkIcrTHYjVOkE2Px5GB8VFaNA\n"
// "GEl38zV4OuYAIWt3Su4esd+gpOVqZ4OFyRuu1EftL/gQPx7TBrfR3L8mNYgOeChT\n"
// "GiVCbvpCXT+iUChkzTW12LTTC4FzOJwy+EjUAmc1vmnp6XaVrEjFVFPMIDoC3IMO\n"
// "xyUDqq6S+ajDCWnScGMKZ2Swyy6jqz02zHq+ws8m69JkmxVhOLrYMBQym4p19wVi\n"
// "kaOj5kQhAh6slOqI59AknEIYSidcW+xYBs4nCF4zLVAKr7uxLfLyUac3lUUX4EhX\n"
// "uPAsbzof0Q63XmfFJjQJXeMl06CzPMncdkhG3qiNdBolEexZcwQx24q6YBaMmY43\n"
// "uoTk9Svfz4YBtdpvo+z0WgaAHCRsB2kgcfLe\n"
// "-----END CERTIFICATE-----\n";
}
